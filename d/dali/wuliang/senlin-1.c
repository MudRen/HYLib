// Modify By River 98/12
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ɭ��");
	set("long", @LONG
���Ų����У��ٲ�̤���ľ��ǰ������ݣ�����û��·,ÿ��һ����������
���̵�С��,����������塣
LONG
	);
        set("outdoors", "����");

	set("exits", ([
           "south" : __DIR__"xiaoxi",
           "north" : __DIR__"senlin-2",
           "west" : __DIR__"senlin-3",
           "east" : __DIR__"senlin-4",
	]));

	setup();
}

void init()
{
        add_action("do_look", "look");
}

int do_look(string arg)
{
        object me = this_player();        
        mixed *local;
        local = localtime(time() * 60);
        if (!arg){
        if(local[2] < 3 || local[2] >= 21) {
          message("vision",BLU"���������һƬ��\n"
          "Խ��Խ�࣬ת�۱㲼��ɽ�ȣ��е�����өƮ�ɣ��е��緱����˸��\n"NOR, me);
          }
         return 0;
      }
}
