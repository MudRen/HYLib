// zhulin5.c ����
// By River 99.5.24
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
          set("short",GRN"����"NOR);
	  set("long",@LONG
�г�����·���������������͵ĺô�һƬ���֣��������ټ��������ï��
�����֣�����������֮��ȷʵ������������Ϣ�Ÿ��������������ת������
���˵�ϲ������������һ��С·ͨ����ɽ��
LONG
);

          set("outdoors","�����"); 
	  set("exits",([
                "east" :  __DIR__"zhulin"+(random(6)+1),
                "south" : __DIR__"zhulin"+(random(6)+1),
                "north" :  __DIR__"zhulin"+(random(6)+1),
                "west" : __DIR__"zhulin6",
          ]));

          setup();
          replace_program(ROOM);
}
