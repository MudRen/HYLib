
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("�һ�������", ({ "taohuadao dizi", "dizi" }) );
       set("gender", "����" );
       set("age", 26);
       set("long",
               "����һ��������һ������ӡ�\n");
       set("combat_exp", 12500);
       set("attitude", "friendly");
 
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
	 

	if (!ob || !present(ob, environment())) return;
	switch( random(2) ) {
		case 0:
			say( "�һ�������˵������λ" + RANK_D->query_respect(ob)
            + "�����һ����ɲ����ף����Կ���"BRED"(help taohuadao)"NOR"������а����ġ�\n");
			break;
		case 1:
			say( "�һ�������˵�������ǵ�����ҩʦ�����黭���������������˼ҵĹ���
 ������ѧ��һ�������ܳ���ͷ���ˡ�\n");
			break;
	}

}
