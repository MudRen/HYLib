#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���޾�");
        set("long",@LONG
��Ȼ��ǰ����һ�䣬һ�����˸߰�Χǽ�������ƺ����ľ��ޱȣ�С·
�������ᴩ����ͨ��Ժ����껨Ժ��������ֲ��ȫ����������--����ÿ
����紵�����������ҡ�ڣ������纣���������һ���˸�����ʹ������
��������������һ��ʯ��·������Զ����
LONG);
	set("outdoors","������");
        set("exits", ([
		"north": __DIR__"yuhua",
		"south": __DIR__"road2", 
	        "east": __DIR__"road3",
		]));
        setup();
        replace_program(ROOM);
}
