#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "ʯ����");
		  set("long",@long
����һ���޴�����磬������ɽ�ز��ĺ������ɣ������ϵ�ͼ��������
�ɵ�ʦ��������ʥ�������ս���ֵķ��ˣ�Ӣ��ͦ�Σ�����һ����ʦ֮��
���������������ɵ�ǰ���ˡ�
long);
		 set("exits",([
"north" : __DIR__"guangchang",
"south" : __DIR__"qianting",
]));

set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
