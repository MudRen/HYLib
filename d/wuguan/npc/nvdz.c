
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("��ĹŮ����", ({ "gumu dizi", "gumu dizi" }) );
       set("gender", "Ů��" );
       set("age", 16);
       set("long",
               "������һλ��ĹŮ���ӣ�һ����¡���\n");
       set("combat_exp", 10500);
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
			say( "��ĹŮ����˵������Ĺ���峾���ף������Ļ������Կ�"BRED"(help gumu)"NOR"��\n");
			break;
		case 1:
			say( "��ĹŮ�������������˵ʦ�磬ʦ�����Ѿ���Ϊ��������µĴ��ˣ�
 ʲ��ʱ���ܴ���ȥ�����أ�\n");
			break;
	}

}
