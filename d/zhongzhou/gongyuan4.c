inherit ROOM;

void create()
{
	set("short", "���ݹ�Ժ");
	set("long", @LONG
���ݹ�Ժ�����������ֵ�һ��������ÿ�³�һ��ȫ������
��ʿ�Ӷ����˴��Ͽ���Ժ��������ʿ�����أ�Ҫ��д��ɲ���
Χǽ�����������ĸ�ʾ��
LONG);
	set("objects", ([
  		__DIR__"npc/zhukao3" : 1,
	]));
	set("no_clean_up", 0);

	set("exits", ([
  		"south" : __DIR__"yanling2",
	]));

        set("outdoors", "zhongzhou");
	set("coor/x", -260);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
