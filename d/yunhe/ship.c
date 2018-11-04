// Room: /d/yunhe/chuancang
// Date: netkill  98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","��ͷ" );
    set("long",  @LONG
����һֻ�󴬵Ĵ�ͷ������Ѿ��ģ�������������￴�羰����
���Ǵ��֡����϶ѷ��ż���ľ�塣��������ƶ� ��ͷ�����ߺ���
��������ȥ��
LONG 
    );
	set("exits", ([
		"enter" :__DIR__"chuancang",
			]));
      set("objects", ([
		"d/qianjin/npc/dancer" : 2,

	]));    
    set("outdoors", "yunhe");
    setup();
		
}
int init()
{
	add_action("do_move","move");
	add_action("do_jump","jump");
}

int do_move( string arg)
{
	object me=this_player();
	if (!arg || arg=="") return 0;
	if (arg=="board" || arg=="muban")
	{message("vision","�㽫ľ���ƿ���¶��һ��С��\n",me);
	 set("exits/down", __DIR__"chuandi");
	call_out("close",5);
	return 1;
	}
}
	
int do_jump(string arg)
{
	object me=this_player();
	if (!arg || arg=="") return 0;
	if (arg=="down")
	{message("vision", HIR"\n��ܲ�������������У�����˷���ˮ����ӿ����\n"+
				"������������û��ʲô���ã������򽭵׳�����ȥ...\n"+
				"���С��������ȥ......\n\n"NOR,me); 
	me->move(__DIR__"jiang");
		
	        me->die();
		return 1;
	}
	if (arg=="riverside" || arg=="hean"  || arg=="�Ӱ�")
	message("vision","��һ���������˺Ӱ���\n",me);
	me->move("/d/hangzhou/duanqiao");
	message("vision", me->name()+"�Ӻ�����������\n",environment(me), ({me}) );
	return 1;
}

void close()
{  delete("exits/down");
}