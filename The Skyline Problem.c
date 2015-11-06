
struct sky{
    int s;
    int e;
    int h;
    struct sky *next;
}sky;
struct sky *create_sky(int s,int e,int h){
    struct sky *temp;
    temp=(struct sky *)malloc(sizeof(struct sky));
    temp->next=NULL;
    temp->s=s;
    temp->e=e;
    temp->h=h;
    return temp;
}
struct sky *temp1;
int use;
void insert_sky(struct sky *head, int s,int e,int h){
    struct sky *temp,*up,*temp2;
    int t;
    temp=head->next;
    up=head;
    if(temp==NULL || temp->s>e){
        if(use==0){
            temp1=create_sky(s,e,h);
            use=1;
        }else{
            temp1->s=s;
            temp1->e=e;
            temp1->h=h;
        }
        temp1->next=temp;
        up->next=temp1;
        use=0;
        return;
    }
    while(s<e){
        if(use==0){
            temp1=create_sky(s,e,h);
            use=1;
        }else{
            temp1->s=s;
            temp1->e=e;
            temp1->h=h;
            temp1->next=NULL;
        }
        if(s<e && temp==NULL){
            up->next=temp1;
            use=0;
            break;
        }
        if(e<temp->s){
            temp1->next=temp;
            up->next=temp1;
            use=0;
            break;
        }else if(e==temp->s){
            if(h==temp->h){
                temp->s=s;
            }else{
                temp1->next=temp;
                up->next=temp1;
                use=0;
            }
            break;
        }else if(e==temp->e){
            if(h<temp->h && s!=temp->s){
                temp1->e=temp->s;
                temp1->next=temp;
                up->next=temp1;
                use=0;
            }else if(h>=temp->h){
                temp->s=s;
                temp->h=h;
            }
            break;
        }else if(e>temp->e){
            if(temp->h>h && s!=temp->s){
                temp1->e=temp->s;
                temp1->next=temp;
                up->next=temp1;
                s=temp->e;
                up=temp;
                use=0;
            }else if(temp->h>h){
                up=temp;
                s=temp->e;
            }else{
                temp2=temp->next;
                free(temp);
                temp=temp2;
                if(temp==NULL){
                    up->next=temp1;
                    use=0;
                    break;
                }
                continue;
            }
        }else if(e>temp->s && e<temp->e){
            if(h>temp->h){
                temp->s=s;
                temp1->h=temp->h;
                temp->h=h;
                temp1->s=e;
                temp1->e=temp->e;
                temp->e=e;
                temp1->next=temp->next;
                temp->next=temp1;
                up->next=temp;
                use=0;
            }else if(h==temp->h){
               temp->s=s;
            }else if(h<temp->h && s!=temp->s){
                temp1->e=temp->s;
                temp1->next=temp;
                up->next=temp1;
                use=0;
            }
            break;
        }
        temp=temp->next;
    }
}
int** getSkyline( int **buildings,int buildingsRowSize, int buildingsColSize, int* returnSize) {
    int i,**r=NULL,rn,le;
    struct sky *head,*temp;
    temp1=NULL;
    use=0;
    head=create_sky(0,0,0);
    if(buildingsRowSize>0){
        head->next=create_sky(buildings[buildingsRowSize-1][0],buildings[buildingsRowSize-1][1],buildings[buildingsRowSize-1][2]);
    }
    for(i=buildingsRowSize-2;i>=0;i--) insert_sky(head,buildings[i][0],buildings[i][1],buildings[i][2]);
    temp=head->next;
    rn=0;

    while(temp!=NULL){
        if(rn>0 && le!=temp->s){
            r=(int **)realloc(r,(rn+1)*sizeof(int *));
            r[rn]=(int *)malloc(2*sizeof(int));
            r[rn][0]=le;
            r[rn][1]=0;
            rn++;
        }
        le=temp->e;
        r=(int **)realloc(r,(rn+1)*sizeof(int *));
        r[rn]=(int *)malloc(2*sizeof(int));
        r[rn][0]=temp->s;
        r[rn][1]=temp->h;
        rn++;
        temp=temp->next;
    }
    if(rn>0){
        r=(int **)realloc(r,(rn+1)*sizeof(int *));
        r[rn]=(int *)malloc(2*sizeof(int));
        r[rn][0]=le;
        r[rn][1]=0;
        rn++;
    }
    (*returnSize)=rn;
    return r;
}
