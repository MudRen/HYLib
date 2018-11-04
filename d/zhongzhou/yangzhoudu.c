#include <ansi.h>
#include <room.h>
inherit ROOM;
#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"yangzhoudu"
#define TO __DIR__"zhongzhoudu"
#include "shiproom.c"
void create()
{
  	set ("short", "���ݽ���");
  	set ("long", @LONG
������ͨ�����ݳǵĶɿڣ���ǰ��Ĺ������� (river)��
�����������۾����������ɴ��������������Ͼ������ݸ�����
��ͣ��ЩС��������һ��С·ͨ�����ݵ����š�
LONG);

        set("arrive_room", "/d/zhongzhou/zhongzhoudu");
  	set("exits", ([
  		"north" : "/d/luoyang/road1",
               
	]));

        set("resource/fish", ({ "/clone/fish/liyu",
                                "/clone/fish/jiyu",
                                "/clone/fish/qingyu",
                                "/clone/fish/caoyu", }));

  	set("outdoors", "city");
        set("coor/x", -10);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        //replace_program(ROOM);
}
