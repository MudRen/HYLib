
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("Ľ�ݵ���", ({ "murong dizi", "dizi" }) );
       set("gender", "����" );
       set("age", 16);
       set("long",
               "����һ����ͺ�������꣬������ǿ��׳��\n");
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
			say( "Ľ�ݵ������յ���Ľ��ɽׯ���������˾����ĵط�����λ" + RANK_D->query_respect(ob)
             + "����ȥĽ��ɽׯ�Ļ������Կ�"BRED"(help murong)"NOR"��\n");
			break;
		case 1:
			say( "Ľ�ݵ����������ϰ�Ŷ�ת���Ƶ����־��������ϳ��������š�\n");
			break;
	}

}
