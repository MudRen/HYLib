
inherit NPC;
#include <ansi.h>
void create()
{
	set_name("������Ů", ({ "dancer" }) );
	set("gender", "Ů��" );
	set("title", HIY "ɴ������" NOR);
	set("age", 18);
	set("long",
		"һ��ɴ�����ʣ���Ұ�Ըе�������Ů\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
        set("chat_chance", 5);
        set("chat_msg", ({
"������Ů˫������İڶ��ţ�\n",
"������Ůȫ�����߰��Ť����������Ŀ�ⷢ����\n",
"������Ů�ڿն�����շ��˼�Ȧ����Ĩ��Ĩ��ߵĿ�ˮ��\n",
        }) );
	set_skill("unarmed",5);
	set_skill("dodge",5);
	setup();
	carry_object(__DIR__"obj/halfcloth")->wear();
}
