inherit NPC;
inherit F_DEALER;
#include <ansi.h>
void create()
{
    set_name("������", ({ "sunshine" }) );
    set("gender", "Ů��" );
    set("age", 17);
    set("title", HIY "��ɫ��"NOR);
        set("long",
        "һ�������Ů���ӣ����ϴ����·���������������Ⱥ�ˮ������\n��Ҳ��δ����������ʣ������������Ů���ӡ�\n");
        set("attitude", "friendly");
        set("class","legend");
        set("chat_chance", 1);
        set("chat_msg", ({
"������ͻȻ������Ц�ݣ���Ȼ����ʥĸǡĸ���������ֻ��Ѫ�������ᣬ\n����ȥǰ����Ѫ����������Ů�������������\n",
"����������һЦ�����Ǹ�С������ȥ�װͰ͵ģ��ı�����Ů�˻�Ҫ����\n",
                }) );
        set("per",30);
        set("combat_exp",3000000);

	set("vendor_goods", ({
               __DIR__"obj/gw_sword",
               __DIR__"obj/gw_spear",
               __DIR__"obj/gw_hammer",
               __DIR__"obj/gw_whip",
               __DIR__"obj/gw_axe",
               __DIR__"obj/gw_blade",
               __DIR__"obj/gw_staff",
               __DIR__"obj/gw_dagger",
               __DIR__"obj/gw_stone",
               __DIR__"obj/gw_iron",
	}));
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("unarmed",100);

        setup();
    carry_object(__DIR__"obj/heipifeng")->wear();
}
void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
        ::init();
}  
