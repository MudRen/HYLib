// baling/nandajie1
// Room in ���� 
// laowuwu 99/04/11
inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�ϴ�����ǳ���ķ����ضΣ�һ�����ϣ�һ�ɵƺ���̣���Ϊ���֡�
Ц�������������������������һƬ��������Ķ��䣬�㲻����Գ����
����ʹ�ͣ������һ����������һ�����ֵĹ㳡��������һ�ҵ��̣�ǽ��
д��һ�����ġ������֣���ϸ��������������ѹ�͵��ּۻ��۵�������
LONG
	);
        set("outdoors", "baling");

	set("exits", ([
		"east" : __DIR__"dangpu",
		"south" : __DIR__"nandajie2",
		
		"north" : __DIR__"guangchang",
	]));

	setup();
	replace_program(ROOM);
}

