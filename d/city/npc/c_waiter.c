//Cracked by Roath
// c_waiter.c ���С��
// xQin 6/00

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("���С��", ({ "chaguan xiaoer", "xiao", "waiter" }) );
        set("gender", "����" );
        set("age", 22);
        set("long",
                "��λ���С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("no_get", "1");
        set("rank_info/respect", "С����");
        set("vendor_goods", ({
        	__DIR__"tea/qimen_hongcha",
        	__DIR__"tea/tie_guanyin",
        	__DIR__"tea/wuyi_yancha",
        	__DIR__"tea/xinyang_maojian",
        	__DIR__"tea/maojian",
        	__DIR__"tea/yinzhen",
        	__DIR__"tea/guapian",
        	__DIR__"tea/maofeng",
        	__DIR__"tea/longjing",
                __DIR__"tea/biluo_chun",

        }));
        setup();
        carry_object("/clone/misc/cloth")->wear();

}

void init()
{       
        object ob; 
        mapping myfam; 

        ob = this_player();

        ::init();
        if( interactive(ob) && !is_fighting() ) {
                if ( (myfam = ob->query("family")) 
                && myfam["family_name"] == "ؤ��" 
                && ob->query_skill("begging",1) > 10 )
                {
                        remove_call_out("saying");
                        call_out("saying", 0, ob);
                }
                else
                { 
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                }
        }

        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "���С��Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "����ʲô�Ը���\n");
                        break;
                case 1:
                        say( "���С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                                + "�������ⶼ�Ǽ�Ʒ�ò裬��Ҫ��ʲô��\n");
                        break;
        }
}

