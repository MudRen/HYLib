// waiter.c
inherit NPC;
void create()
{
        set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "����" );
        set("age", 22);
        set("long",
                "��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "С����");
        setup();
          carry_object("/clone/misc/cloth")->wear();
}
void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "��Ҫס������������\n");
                        break;
                case 1:
                        say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                                + "����������С�껹�м����Ϻõķ��䡣\n");
                        break;
        }
}
int accept_object(object who, object ob)
{
        
        if (ob->query("money_id") && ob->value() >= 100) 
        {
                tell_object(who, "С��һ������˵������л���ϣ��͹�����¥ЪϢ��\n");
                who->set_temp("rent_paid",1);
                return 1;
        }
        return 0;
}

