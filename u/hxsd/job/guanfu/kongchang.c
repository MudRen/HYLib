// /d/city/kongchang

inherit ROOM;

void create()
{
	set("short", "�㳡");
	set("long", @LONG
���Ǳ�Ӫ�Աߵ�һƬС�ճ����ڶ��ߵ�ǽ�����˼��Źٸ�����׽��
��͢Ҫ���ĸ�ʾ������Χ������࿴���ֵ��ˣ����в���һЩ���ָ��֣�
����Ҫ׽�õ�Ҫ���������֣������������Ұ񡣵�Ҳ�в������ֺ���
֮����һ��ԾԾ���ԡ�
LONG
	);

	set("exits", ([
		"west" : "/d/city/bingyin",
		 
	]));
        set("objects", ([
                "/quest/guanfu/npc/yayi" : 1,
        ]));
	 
	setup();
}
#include "/quest/guanfu/job2.h"
