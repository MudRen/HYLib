inherit ROOM;
void create()
{
        set("short", "ľ����");
        set("long", @LONG
����һ��ľ���꣬������ɢ���ż������õ����ӡ����׵�ǽ�Ͽ��ż�����
�õ�ľ�壬���׹��Ÿ���ľ�����ߡ�����û�����ڣ�������֪��������ȥ�ˡ�
LONG );
        set("exits", ([
                "north" : __DIR__"stxijie2",
	]));

	setup();
}
