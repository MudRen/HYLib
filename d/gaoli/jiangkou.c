// /d/gaoli/xuanwumen
#include <ansi.h>


inherit ROOM;


void create()
{
	set("short", "�뽭��");
	set("long", @LONG
�뽭������Ҳ���൱���֣��������ɿ�������һ����ֱ����·ֱͨ
ɽ���ء��˵���紾�ӣ�·�Լ��������������������Ҷ���һ�����
���ơ���ӭ��Ʈ�εΪ׳�ۡ�Ҳ�в���С����·��������ѱ棬ȴ
Ҳ����ʢ����ȴ��
LONG
	);

	set("exits", ([
		"west" : __DIR__"dadao1",
                "southwest" : __DIR__"yucun",
		"east" : __DIR__"jiangdong",

	]));
	set("objects", ([
"quest/skills2/wunon/non/nontian" : 2,   
	
	]));

	set("outdoors", "/d/gaoli/hunjiangkou");
	setup();
}

