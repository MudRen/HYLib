// This is a room made by wsl.
#include <room.h>
inherit ROOM;
void create()
{
    set("short", "̫����");
    set("long", @LONG
�������ǵġ�ʫ�ɡ�����ڳ�����ס��,�߽�̫����,����ҹ������������
���˲����԰�顱��ʫ�ɵ�������������Ҳ��ô���Ŀ̹ǡ������ܶ�
ʹ̫�����ڵ�һ�д���Ũ�ص���Ӱ�£��������ȴ��Ŷ�����ǰ��Ͷ���Ĺ�
��������̫���õ�ʯ��ʱ�����ܸе���ײ������ţ���������������ʫ��
��ɽ��
LONG
    );
    set("exits", ([
         //"south" :__DIR__"ca6",
         "northeast" :__DIR__"ca7",
    ]));
    //create_door("south", "����", "north", DOOR_CLOSED);
    setup();
    replace_program(ROOM);
}
