inherit NPC;
int about_cry();
void create()
{
     set_name("С����",({"xiaohai","kid","xiaohaizi"}));
     set("shen_type",1);
     set("gender","����");
     set("age",5);
     set("combat_exp",400);
     set("str",13);
     set_skill("unarmed",13);
     set_skill("parry",10);
     set_skill("dodge",10);
     set("inquiry",([
            "cry":(:about_cry:),
            "��":(:about_cry:),
            ]));
    set("chat_chance",3);
    set("chat_msg",({
          "С����͵͵�������Ĩ��Ĩ����!\n",
          "С��������ӯӯ�ؿ�����.\n",
               }));
     setup();
     carry_object("/clone/misc/cloth")->wear();
     add_money("coin",30);
  }
int about_cry()
{    object ob;
      ob=this_object();
      if (present("ren fanzi",environment(ob)))
     {message_vision("$N���ӵؿ��˿��˷��ӣ�����ͷ,��������!\n",ob);
         return 1;
      }
       command("say ���Ҳ����ؼҵ�·��!\n");
       return 1;
}