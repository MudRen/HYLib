inherit NPC;
string *name=({"����","��Ů","Ա��","����","����","С��","ǿ��"});
string *gender=({"��","Ů","��","Ů","��","Ů","��"});
string *id=({"shusheng","shinu","yuanwai","furen","gongzi","xiaojie","qiangdao"});
void create()
{
    int i;
    i=random(sizeof(name));
    set_name(name[i],({id[i]}));
    set("gender",gender[i]+"��");
    set("attitude","friendly");
    set_skill("unarmed",10);
    set("chat_chance",1);
       set("chat_msg",({
            (:random_move:),
     }));
    setup();
add_money("coin",30);
carry_object("/clone/cloth/cloth")->wear();
}
