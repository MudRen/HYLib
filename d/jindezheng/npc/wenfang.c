#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

string query_save_file() { return DATA_DIR + "npc/�·���"; }
void create()
{
string OBJ_DIR;


        OBJ_DIR="/d/jindezheng/obj";
	set_name("�·���", ({ "wenfanghai", "wenfanghai", "wenfanghai" }) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��λ�·�����Ц�����æ����\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");

	set("vendor_goods", ({
		OBJ_DIR+"/guanyin",
		OBJ_DIR+"/shuijinpin",
		OBJ_DIR+"/erping",
OBJ_DIR+"/haierzheng",
OBJ_DIR+"/qiankunhu",
	
	}));
	set("area_name","�������¼��ϵ�");
	set("area_file","/d/jindezheng/china-shop.c");
	set("ziyuan","����");
	set("jizhi",80);
	set("kaifa",20);



	setup();
 carry_object(__DIR__"obj/fucloth")->wear();
 carry_object("/clone/weapon/changjian")->wield();
}
void init()
{
  object ob;
 ::init();
 if (interactive(ob=this_player())&&!is_fighting()) {
   remove_call_out("greeting");
   call_out("greeting",1,ob);
    }
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}
void greeting(object ob)
{
  if (!ob||environment(ob)!=environment()) return;
  switch(random(3))    {
   case 0:
       command("say �������ٱ��ꡣ");
       break;
   case 1:
       command("say ��λ"+RANK_D->query_respect(ob)+",����Ĵ����ھ���������һָ.\n");
       break;
   case 2:
       command("say �⼸��������������,���ô�Ҥ����Щ����!\n");
       break;
       }
  return;
}
