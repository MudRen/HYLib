// shulin4.c
// Modify By River 98/12
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "ɽ������");
	set("long", @LONG
�������£������ȣ����о����ĵģ���˵�˼�����������Ҳ�ް�㣬Ψ
��������䣬ң��ͺ��������ٲ��������Ͽ�ȥ��ֻ���ٲ�֮��һ��ʯ�ڹ���
���񣬲�֪������ĳ弤ĥϴ���Ž������ʯ��ĥ�����ƽ����������ˮ����
�٣��Ž���Ƭ����������������ʯ��¶�˳�����
LONG
	);
        set("exits", ([
	    "south" : __DIR__"beihubian",
        ]));
        set("outdoors", "����");
	set("objects", ([
	   __DIR__"obj/yeguo" : 2,
        ]));
 
	setup();
}

