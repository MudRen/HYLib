inherit ROOM;
#include <room.h>
void create()
{
        set("short", "�᷿");
        set("long", @LONG
�˷�С�����ࡣǽ��һС���������ɫ�����۵͡�ǽ����һ���ã��ϸ��첼����
���ܾ�û���ù������ӡ��������һ�����Ե���
                        �����޼۱����ѵ������ɡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"corror3",
]));
        set("objects", ([
        __DIR__"npc/chick2" : 1,
                        ]) );


        set("coor/x",-200);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        create_door("south", "ľ����", "north", DOOR_CLOSED);

}
