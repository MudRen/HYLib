// /d/zhuojun/road1.c
// Room in �ÿ�
// modify by yang

inherit ROOM;

void create()
{
	set("short", "´ɽ��");
	set("long", @LONG
´ɽ����������´ɽ�Ĺ������У��������Ͽ�������׺�Ȫǰ�
���ص��㡢�������������������ơ������ֺ���Ϊ����������ʦ��
������"��κ�����ʤ�������һ����"֮��������ǧ�ֹ���ׯ�ϴ���
����Ժ�ڱ��������������ɣ���Ϊ´ɽ���ƾ���ʷ�Ļ��֤��
LONG);

	set("exits", ([
		"north": __DIR__"nanmen",
		"south": __DIR__"road6",
		
	]));

       set("objects",([
                __DIR__"npc/shang" : 2,
        "/d/shaolin/npc/xiao-bei" : 2,
        ]));
 	set("outdoors", "zhuojun");
	setup();
	replace_program(ROOM);
}



