inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���������ڳ���Ψһһ�������̡�ǰ�����һ����¯��һλ�����Ǻ��Ĵ�
������æ�Ŵ��쳤������˵����Ϊ��������������Ӳ�ޱ������в��ٽ�����
ʿ����������������
LONG );
        set("exits", ([
                "east" : __DIR__"stbeijie1",
	]));

	set("objects", ([
                __DIR__"npc/tiejiang" : 1,
      	]));
	setup();
}
