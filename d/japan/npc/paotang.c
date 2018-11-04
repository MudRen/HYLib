// Npc: japan/npc/paotang.c

inherit NPC;
inherit F_DEALER;
#include <ansi.h>

void create()
{
         set_name("��������",({"longben dashu","longben","dashu"}));
        set("gender", "����" );
        set("age",42);
        set("title","�񻧺��ʵ�");
        set("long",
                 "���ʵ���������������ʵ�������������΢Ц�š�\n");
        set("combat_exp",150);
        set("attitude", "friendly");
        set("rank_info/respect","����");


set("vendor_goods", ({
                __DIR__"obj/youyu",
                __DIR__"obj/yupian",
                __DIR__"obj/fantuan",
                __DIR__"obj/jiuhu",
	}));
        setup();
        add_money("silver",5);
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
        add_action("do_list", "list");
        add_action("do_buy", "buy");

}

void greeting(object ob)
{

        if( !ob || environment(ob) != environment() ) return;
         switch( random(5) ) {
                case 0:
               message_vision("$N�첽��ǰ������λ"+
               RANK_D->query_respect(ob)+"���Щʲô��\n",this_object(), ob);
                        break;
                case 1:
             message_vision("$n������$N������$N��ˡ�\n",ob,this_object());
                        break;
                           }
}
