
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("��ͯ",({"oscar"}));
	set("nickname", HIY"�Ժ���"NOR);
	set("gender", "����");
	set("age", 20);
	set("long", 
		"�����ǹԺ���oscar��\n");

	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
