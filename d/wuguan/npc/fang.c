#include <ansi.h>
inherit NPC;

void create()
{
	set_name("������", ({ "fang xiansheng", "fang", "xiansheng"}));
	set("long", "��λ������Ͳ�����������ض��顣\n");
	set("gender", "����");
	set("age", 35);
	set_skill("literate", 60);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 20);
	set("combat_exp", 500000);
	setup();
        carry_object("clone/cloth/cloth")->wear();
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

int recognize_apprentice(object ob)
{
	int money=25, level = ob->query_skill("literate", 1);

	if (level>29) money=50;
	if (level>50) money=100;
	if (level>89) money=1000;
	if (level>119) money=5000;

	ob->delete_temp("mark/literate");
//	switch(MONEY_D->player_pay(ob, money)) {
//		case 0:
//		case 2:
//			write("�����ڵ�ѧ����ÿ��" + MONEY_D->money_str(money) + "���뱸����Ǯ��\n");
//			return 1;
//	}
	ob->set_temp("mark/literate", 1);
	return 1;
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

       if ( ob->query_skill("literate") > 60 ) return;

       command("pat "+ob->query("id"));
       command("say ��λ" + RANK_D->query_respect(ob)
				+ "��������ѧЩ֪ʶ"HIR"(xue fang literate)"NOR"�ɡ�\n");

}

int is_apprentice_of() {return 1;}

