// mishi.c ����
// mlf���,lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","����");
        set("long",
"����һ�����ң�����ܰ��������м����һ�����ӣ�����һ��ҹ����
��ɢ������͵Ĺ�â��ʹ������ϡ������Χ��һ�У�ǽ�Ϲ���һ��ɽˮ��
��hua����ǽ����һ����ܣ���ܣ�shelf���Ϸ���һЩ�飨book����\n"
	);
	set("valid_startroom",1);
	set("exits",([
		"out" : __DIR__"woshi",
	]));
         set("item_desc",([
		"shelf" : "������һ�����Ƶ��顣\n",
          ]));
	set("book_count",1);
	setup();
}

