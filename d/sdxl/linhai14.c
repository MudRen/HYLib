// sdxl
// by dubei
#include <ansi.h>;
#include <room.h>
inherit ROOM;


void create()
{
	set("short", "�ֺ�");
	set("long", @LONG
������һƬһ�������ֺ���ÿ����ľ����ʮ���ɸߣ���Χ��İ
����������о����Լ���·��
LONG
	);
	set("exits", ([
		"northeast" : __DIR__"linhai14",
		"southeast" : __DIR__"linhai14",
		"northwest" : __DIR__"linhai14",
		"southwest" : __DIR__"linhai14",
		"south" : __DIR__"linhai14",
		"east" : __DIR__"linhai14",
		"north" : __DIR__"linhai14",
		"west" : __DIR__"linhai14",
	]));

	set("outdoors", "xiangyang");
	setup();
           
}
mapping *quest = ({"northeast","southeast","northwest","southwest",
                                "south","east","north","west",});
 
int valid_leave(object me, string dir)
{
//           if(dir == "northeast") return ::valid_leave(me, dir);
           if (dir == me->query_temp("xtj_fx")){
           message_vision(RED"$N�о���ƣ��������Ȼ����Զ����¡¡��ˮ��������˳����ȥ��\n"NOR, me);
           me->move(__DIR__"pubu");
           me->delete_temp("xtj_fx");      
            message("vision", me->name() + "���ֺ���һͷ���˳�����\n", environment(me), ({me}) );
          }
          else{
          me->move(__DIR__"linhai"+(random(13)+1));
          me->delete_temp("xtj_fx");         
       }
    return notify_fail("");
}
void init() 
{
      object ob=this_player();
    mapping fx;
        fx = quest[random(sizeof(quest))];
      if (interactive(ob) && !ob->query_temp("xtj_fx"))
           ob->set_temp("xtj_fx",fx);
 
}
