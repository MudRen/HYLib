// /d/zhuojun/dangpu.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
���߽����̣�����һλ�������������������˵�ǵ��곯ͥ�Ĺ��
�����Ƿ��������ļۼ������ǽ�����ԣ�����ǰ���䵱�������˾������
�˴�ѯ�ʼ�ֵ��
LONG
	);
set("exits", ([
                "south"  :__DIR__"xidajie2",
	]));
	set("objects",([
	__DIR__"npc/qiao":1,
	]));
       setup();
	replace_program(ROOM);
}	
