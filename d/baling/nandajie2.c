// baling/nandajie2
// Room in ���� 
// laowuwu 99/04/11
inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
������һ�������Ľֵ��ϣ����ϱ���ͷ���졣�ϱ����ϳ��ţ�����
ͨ�������ģ�����һ�������¥������������Ц���Ǿ���������������
��Ժ��������Ǽ���ʦ�ĸ�ۡ��
LONG
	);
        set("outdoors", "baling");

	set("exits", ([
		"north" : __DIR__"nandajie1",
                "south" : __DIR__"haozai",
                "west" : __DIR__"nandajie3",
                "eastup" : __DIR__"micunyuan",
	]));

	setup();
}

