// /d/taiyuan/yizhan.c
// Room in ̫ԭ
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "��վ");
	set("long", @LONG
����һ��ʮ����ͨ����վ��ר�Ÿ���ٷ����飬�ż��Ĵ��ͣ�����
�Ĺ������Ⱦ�Ҫ�������
LONG
	);
set("outdoors", "taiyuan");
set("exits", ([
                "north" : __DIR__"xidajie1", 
	]));
	

       setup();
	replace_program(ROOM);
}
