// lin.c
// Last Modified by winder on May. 29 2001

inherit NPC;
#include <ansi.h>
void create()
{
	set_name("������", ({ "lin shaoning", "lin" }));
	set("long", "��������Ȫ����ݹݳ���\n");
	set("gender", "����");
	set("age", 35);
	set_skill("dodge", 180);
	set_skill("force", 180);
	set_skill("parry", 180);
	set_skill("claw", 180);
	set_skill("hand", 180);
	set_skill("strike", 180);
	set_skill("finger", 180);
	set_skill("cuff", 180);
	set_skill("blade", 180);
	set_skill("stick", 180);
	set_skill("club", 180);
	set_skill("staff", 180);
	set_skill("sword", 180);
	set_skill("throwing", 180);
	set_skill("changquan", 140);

	map_skill("cuff", "changquan");
	map_skill("hand", "sanshou");
	prepare_skill("cuff", "changquan");

	set("combat_exp", 400000);
	set("shen_type", 1);
	setup();

}
int accept_object(object who, object ob)
{
	if (who->query("combat_exp")>= 3500)
	{
		message_vision("����������$N˵������书Ӧ���������������ٳ�����������û�������ˡ�\n", who);
		return 0;
	}
	if (ob->query("money_id") && ob->value() >= 500)
	{
		who->set_temp("marks/quanzhou_paied",1);
		message_vision("��������$N˵���ã���λ" + RANK_D->query_respect(who) + "��ѧʲô�أ�\n" , who);
		return 1;
	}
	else
		message_vision("��������ü��$N˵��Ǯ�Ҳ��ں�������Ҳ����Ҳ̫���˵���ɣ�\n", who);
	return 0;
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("marks/quanzhou_paied")==1) return 0;
	return 1;
}


