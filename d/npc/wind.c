
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����", ({"wind"}));
	set("nickname",HIC"�����ſ�ɽ��ʦ"NOR);
	set("gender", "����");
	set("age", 20);
	set("long", 
		"�����ǵ���ķ磬һ��ƽ�����Ժ󣬹������ˣ�����ɽ�ȡ�\n"+
                "������������ƣ������ǡ��������Գ������֡�\n");
	

	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
