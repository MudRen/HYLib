// shanya.c
// bbb 1997/06/11
// Modify By River 98/12
#include <ansi.h>
int get_object(object ob);
inherit ROOM;

string look_down();
void create()
{
	set("short", "������");
	set("long", @LONG
�߳�ʮ�������������ɽ����ĺ�ɽ���������������ɽ��أ��κ�����
�������롣��������ܲ���ɽʯ���졣�Ա߾���һ����׵�����(cliff)��
LONG
	);
	set("exits", ([
		"northwest" : __DIR__"pubu",
	]));
        set("outdoors", "����");
        set("objects", ([
            __DIR__"obj/yeguo" : 2,
        ]));

	set("item_desc",([
	   "cliff" : (: look_down :),
	   "down" : "�����ãã��ʲôҲ��������\n"
	]));
	setup();
}

void init()
{
	add_action("do_jump", "tiao");
        add_action("do_jump", "jump");
}

int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}

int do_jump(string arg,object *obj)
{
	object me= this_player();
        object *inv = deep_inventory(me);
        if (!arg || arg !="down") return 0;
        if(sizeof(obj)){
         message_vision(HIR "$N���²�һ���գ�����������������һ���ҽУ�����ֱ׹��ȥ��\n"NOR, me);
         me->receive_wound("qi", 20);
         me->unconcious();
         me->move(__DIR__"xiaoxi");
         return 1;
         }
 if ( me->query("dali/meet_dy1") || (random((int)me->query("kar")) >10)){
	 message_vision(HIR "$N���²�һ���գ�����������������һ���ҽУ�����ֱ׹��ȥ��\n" 
         "$N׹�°����ɣ�ײ���±�һ�ù����ϣ����˼�������׹�ľ���ȴҲ���ˡ�\n" NOR, me);
         me->move(__DIR__"bankong");
	 return 1;
         }
         message_vision(HIR "$N���²�һ���գ�����������������һ���ҽУ�����ֱ׹��ȥ��\n"NOR, me);          
         me->receive_wound("qi", 20);
         me->unconcious();
         me->move(__DIR__"xiaoxi");
         return 1;
}

string look_down()
{
	return  "����(down)��ɲ⣬�����������ף������Ҫ��ɱ���⵽�Ǹ��õط���\n";
}
