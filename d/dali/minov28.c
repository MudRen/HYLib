//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "��ɽ����");
	set("long", @LONG
һ��Ƭï�ܵĳ������������ڰ�ɽ���Ļ����ϡ����ӶԴ������
��������˵�ǣ�������Ҫ�Ľ������ϣ�Ҳ���ճ�������Ʒ��ԭ���ϡ�
ɽ�µĴ�ׯ��İ����˾�����ɽ���ɷ����ӡ�����ɽ����Ϫ���£���
����ˮ���Ѿ��Ĵ�ɽ�񾭳��ѿ����µ����Ӷ���Ϫ�У�����˳ˮƮ
���������Ӹ�����Ϫˮ������������
LONG
        );

	set("exits", ([
		"northup" : __DIR__"minov27",
		"east" : __DIR__"minov31",
		]));

	set("objects", ([
		__DIR__"npc/byshanren1.c" : 2,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
