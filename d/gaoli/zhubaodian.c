// /d/gaoli/zhubaodian
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�鱦��");
	set("long", @LONG
����һ��ר�ų��۹��ر�����鱦�ꡣ�����鱦����ƵĹ����ɫ��
�����ɫ���㿴����������챦�����ۻ����ң�����������
LONG
	);
set("exits", ([
                "east":__DIR__"zhuque-1",   
	]));
      set("objects", ([
		"/d/gaoli/npc/zhu" : 1,
	]));
       setup();
	replace_program(ROOM);
}
