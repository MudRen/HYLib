inherit NPC;
int give_work();
void create()
{
      set_name("��ȱ",({"songque","jiangong","song"}));
      set("gender","����");
      set("nickname","�๤");
      set("age",40+random(40));
      set("shen_type",-1);
      set("combat_exp",300000+random(400000));
      set("str",45);
      set("per",16);
      set("inquiry",([
              "work":(:give_work:),
              "job":(:give_work:),
              "����":(:give_work:),
      ]));
      set_skill("unarmed",115);
      set_skill("parry",115);
      set_skill("dodge",115);
      setup();
      carry_object("/clone/misc/cloth")->wear();
      add_money("gold",2);
 }
void init()
{  object ob;
    ::init();
      if (interactive(ob=this_player())&&!is_fighting())
          {   remove_call_out("greeting");
               call_out("greeting",1,ob);
           }
   add_action("do_say","say");
}
void greeting(object ob)
{   if(!ob||environment(ob)!=environment()) return;
    if (ob->query_temp("work/kan")==1) return;
       if (ob->query_temp("work/kan")==2)
             {    command("say ��,"+ob->query("name")+"�Ѿ������ˣ�����(say ������).\n");
                  return;
             }     
    command("say ��λ"+RANK_D->query_respect(ob)+"��Ҫ�ҹ���ô������(ask song about work).\n");
    return;
}
int give_work()
{
    object me;
    me=this_player();
    if (!me||environment(me)!=environment()) return 0;
    if (me->query_temp("work/kan")==1)
   {    command("say ��ղŵĻû�����!\n");
            return 1;
       }
    if (me->query_temp("work/kan")==2)
     {        command("say ��Ĺ�Ǯ��û���أ��ҿɲ����㱣��!\n");
               return 1;
     }
    command("say ��!����͵����������ȥ��ľ��!\n");
    me->set_temp("work/kan",1);
    return 1;
}
int do_say(string str)
{   object ob,ob1;
     int money;
    ob=this_player();
    if (!str||str!="������") return 0;
    if (ob->query_temp("work/kan")!=2)
       {    command("say ����ƭǮô����!\n");
             return 0;
        }
    money=1+random(5);
    command("say �ɵúã�������Ĺ�Ǯ.\n");
    ob1=clone_object("/clone/money/silver");
    ob1->set_amount(money);
    ob1->move(ob);
    message_vision("$N�ݸ�$nһЩ����!\n",this_object(),ob);
    ob->delete_temp("work/kan");
    return 1;
} 