// Room: /d/quanzhou/dagou.c
// Date: May 7, 96   Jay
#include <ansi.h>
#include <room.h>
#include <command.h>
inherit ROOM;
int consider_lv(object ob,int a);

void create()
{
	set("short", "�򹷸�");
	set("long", @LONG
�򹷸�λ��̨���ϲ��������С�������е���������
�ھ�����Ͽ�壬��ǫ̈̄��һ���ۡ�
    ���⺣�ۣ����̴�(chuan)ǰ����孡�
LONG );
	set("exits", ([
                "east" : "/d/taiwan/dagougang",
                "north" : __DIR__"chiqian",
	]));
	set("item_desc", ([
                "chuan" : "һ���̴���������(shangchuan)ȥ��孡�\n",
	]));
	set("objects", ([
		__DIR__"npc/wokou": 4,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
//	replace_program(ROOM);
}

void init()
{
    add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
	object me, ob,room;
    if( !arg || arg !="chuan" ) 
       {
         tell_object(this_player() , "��Ҫ ������ȥ��\n" ) ;
         return 1 ;
       }
    if (!room=find_object("/d/feitian/dahai"))
    room=load_object("/d/feitian/dahai");
    me = this_player () ;
if (me->is_busy())
       {
         tell_object(this_player() , "����æ����!\n" ) ;
         return 1 ;
       }
if (me->is_fighting())
       {
         tell_object(this_player() , "����������!\n" ) ;
         return 1 ;
       }
    message_vision("���ϴ�һ�������ϴ���æ����һ��������ඣ�\n", me);
    message_vision("�������𷫣����������ȥ��\n", me);
    me->move(room) ;
    tell_object(me, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
if (random(10) > 7)
{
		message_vision(HIB"ͻȻ�����ϳ�����һ�㺣������һ�����������˴�.......\n"NOR, me);
		message_vision(HIB"�������һ�������е���ͨͨ������������������\n"NOR, me);

		ob = new("/d/feitian/npc/wokou");
              ob->set("combat_exp",me->query("combat_exp") * 8 / 10);
		ob->set("max_qi",me->query("max_qi")* 3 / 4);
		ob->set("eff_qi",me->query("max_qi")* 3 / 4);
		ob->set("qi",me->query("max_qi")* 3 / 4);
		ob->set("max_jing",me->query("max_jing")* 3 / 4);
		ob->set("eff_jing",me->query("max_jing")* 3 / 4);
		ob->set("jing",me->query("max_jing")* 3 / 4);

		ob->set_skill("force", consider_lv(ob, 8));
		ob->set_skill("unarmed", consider_lv(ob, 8));
		ob->set_skill("xuanhualiu-quanfa",consider_lv(ob, 8));
		ob->set_skill("dodge", consider_lv(ob, 8)); 
                ob->set_skill("blade", consider_lv(ob, 8)); 
		ob->set_skill("aikido", consider_lv(ob, 8)); 
		ob->set_skill("wuxing-dun", consider_lv(ob, 8)); 
		ob->set_skill("shayi-xinfa", consider_lv(ob, 8));
		ob->set_skill("parry", consider_lv(ob, 8)); 
		ob->set_skill("literate", consider_lv(ob, 8)); 
		ob->set_skill("feitian-yujianliu", consider_lv(ob, 8)); 
                        ob->map_skill("parry", "aikido");
                        ob->map_skill("unarmed", "aikido");
                        ob->map_skill("dodge", "wuxing-dun");
                        ob->map_skill("force", "shayi-xinfa");
                        ob->map_skill("blade", "feitian-yujianliu");
		ob->move(environment(me));
		ob->kill_ob(me);
		me->kill_ob(ob);
		me->start_busy(1);
call_out("rfeitian", 50 , me );
}
else    call_out("rfeitian", 20 , me );
    return 1 ;
}

void rfeitian( object me )
{
    if (!me || me->is_ghost()) return;
  tell_object(me , "����������ô�����ڵִ���һ�������˶�孵�һ���ۿڡ�\n" ) ;
  me->move ("/d/japan/haigang.c") ;
}


int consider_lv(object ob,int a)
{
	int level; 
	float exper;

	exper = to_float(ob->query("combat_exp"));
	level = ceil( pow( exper*10.0, 0.333333) );

	level = level * a / 10;

	return level;
}
