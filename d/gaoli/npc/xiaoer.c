// ����˫����
 
// xiaoer.c

inherit NPC;

void create()
{
      
       set_name("��С��", ({"xiao er","xiaoer","xiao","waiter","er"}));
       set("shop_id",({"waiter","xiaoer","xiao","er"}));
       set("shop_title","��С��");
       set("gender", "����");
        set("combat_exp", 1000);
       set("age", 26);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);

       setup();

       carry_object("/d/gaoli/obj/cloth")->wear();
       add_money("silver", 1);
}



void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) {  // 1/3 chance to greet.
                case 0:
                        say( name()+"Ц�����˵������λ" +
RANK_D->query_respect(ob)
                                + "������ЪЪ�ţ������Ѱɡ�\n");
                        break;
        }
}

int accept_object(object who, object ob)
{
   if (ob->query("money_id") && ob->value() >= 300) 
   {
     tell_object(who, "С��һ������˵������л���ϣ��͹�����¥ЪϢ��\n");
     who->set_temp("rent_paid",1);
     return 1;
   }
   return 0;
}