//Cracked by Kafei
// group bwdh/room west xiangfang
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "entrance.h"
#include "xiangfang.h"
#define BOARD "/clone/board/bwboard"

void death_stage(object ob, int stage);
void setup_weishi(object weishi,object ob);

void create() {
	 set("short", "���᷿");
	 set("long", @LONG
���������᷿�����������ѡ�����������׼���볡��
�᷿������߼���������(jia)�������˱�����
LONG
	 );

	 set("no_fight",1);
	 set("no_death",1);

	 set("exits", ([
		  "up"    : __DIR__"wizroom",
//        "west" : __DIR__"kantai_w1",
	 ]));
	 create_xiangfang();
	 setup();
}

void init() {
	 init_xiangfang();
	 go_xiangfang();
	 call_out( "death_stage", 90, previous_object(), 0 );
}


void death_stage(object ob, int stage)
{
	object weishi,*weishis;
	int nMyWeiShi=0,nOtherWeiShi=0;
	int i;
	object board;

	if( !ob || !objectp(ob) || !userp(ob) ) return;

	tell_object(ob, HIW "һ�������Ũ��ͻȻ���֣��ܿ�ذ�Χ���㡣\n\n" NOR );
	//if( !ob->query("sjsz/team_name") ) ob->set("sjsz/team_name",HIR"������"NOR);
	ob->set("sjsz/fighting",1);
	ob->set("sjsz/red",1);
	ob->delete("sjsz/white");

	if( !ob->query("sjsz/team_name") )
	{
		board =  find_object(BOARD);
		if (!objectp(board)) {
				  board = load_object(BOARD);
				  if (!objectp(board))
						return;
		}
		ob->set( "sjsz/team_name",board->query("westname") );
	}

	ob->set_temp("apply/short", ({HIW""+ob->query("sjsz/team_name")+"  "NOR+ob->name()+"("+ob->query("id")+")"}));
	ob->move("/d/bwdh/sjsz/wgate.c");
	message("vision",
					 "���Ȼ����ǰ�����һ����Ӱ��\n", environment(ob), ob);

	weishis = filter_array(children(__DIR__"npc/weishi.c"), (: clonep :));

	for( i = 0; i < sizeof(weishis); i++)
	{
		weishi = weishis[i];
		if( weishi->query("sjsz/team_name") == ob->query("sjsz/team_name") )
			nMyWeiShi++;
		else nOtherWeiShi++;
	}

	if( nMyWeiShi > nOtherWeiShi+3 || nMyWeiShi >8  ) return;

	weishi = new (__DIR__"npc/weishi.c");
	if(!weishi)return;

	if(random(4)==1)
		weishi->move(__DIR__"wtang");
	else
		weishi->move(__DIR__"room_01");			

	setup_weishi(weishi,ob);
	message("vision",
					 "���Ȼ����ǰ�����һ����Ӱ��\n", environment(weishi), weishi);
}

void setup_weishi(object me,object obj)
{
	mapping skills;
	string *names;
	int level,i;
	int exp;

	if(!objectp(me) || !objectp(obj) )return;

	exp = 10000000 - obj->query("combat_exp");
	if( exp < 0 ) exp = 100000;

	me->set("combat_exp", exp );

	level = pow( exp*10.,0.33333 );
	if(level < 10) level = 10;

	if( obj->query("combat_exp") < 300000 )
	{
		level = level/2 + random(level*2/3);
	}
	else if( obj->query("combat_exp") < 500000)
	{
		level = level/2 + random(level/2);
	}
	else if( obj->query("combat_exp") < 800000)
	{
		level = level/2 + random(level/3);
	}
	else if( obj->query("combat_exp") < 1000000)
	{
		level = level/2 + random(level/4);
	}
	else
		level = level/2 + random(level/5);

	skills = me->query_skills();
	names = keys(skills);

	for (i=0; i<sizeof(names); i++) {
	  me->set_skill(names[i], level);
	}

	me->set("sjsz/team_name",obj->query("sjsz/team_name"));
	if(exp > 8000000)me->set("name","�ؼ���ʿ");
	else if(exp > 6000000)me->set("name","һ����ʿ");
	else if(exp > 4000000)me->set("name","������ʿ");
	else if(exp > 2000000)me->set("name","������ʿ");
	else if(exp > 500000)me->set("name","�ļ���ʿ");
	else me->set("name","�弶��ʿ");

	me->set_temp("apply/short", ({HIW""+obj->query("sjsz/team_name")+"  "NOR+me->name()+"(wu shi)"}));
}


int do_open(string arg) {
	 if ( !wizardp(this_player()) )
		  return notify_fail("�㲻����ʦ��\n");
	 if (!arg || (arg != "entrance" && arg != "exit") )
		  return notify_fail("��Ҫ��ʲô��\n");
	 if( arg == "entrance" )
	 {
		 if ( query("exits/east") )
		  return notify_fail("���䳡����Ѿ��Ǵ򿪵ġ�\n");
		 set("exits/east", __DIR__"wgate");
	 }
	 else
	 {
		 if ( query("exits/west") )
			  return notify_fail("���䳡����Ѿ��Ǵ򿪵ġ�\n");
		 set("exits/west", __DIR__"kantai_w1");
	 }
	 message_vision("$N����ָ���һ�㣬֨��һ�������˱��䳡��ڡ�\n", this_player());
	 remove_call_out("close");
	 call_out("close", 60);
	 return 1;
}


int close() {
	 message("vision", "���䳡��������ع����ˡ�\n", this_object());
	 delete("exits/west");
	 delete("exits/east");
	 return 1;
}

int auto_open() {
	 if ( query("exits/east"))
		  return notify_fail("���䳡����Ѿ��Ǵ򿪵ġ�\n");
	 set("exits/east", __DIR__"wgate");
	 message("vision", "��֨��֨��ѽ���������䳡����������ˡ�\n", this_object());
	 remove_call_out("close");
	 call_out("close", 60);
	 return 1;
}

int auto_out_open() {
	 if ( query("exits/west") )
		  return notify_fail("���䳡����Ѿ��Ǵ򿪵ġ�\n");
	 set("exits/west", __DIR__"kantai_w1");
	 message("vision", "��֨��֨��ѽ���������䳡����������ˡ�\n", this_object());
	 remove_call_out("close");
	 call_out("close", 60);
	 return 1;
}


int valid_leave(object player, string dir) {
	 if (!wizardp(player) && dir == "up")
		  return notify_fail("�˼����˲�û��������ȥ���\n");
	 return ::valid_leave(player, dir);
}
