// Room: /d/yunhe/chuancang
// Date: netkill  98/08/18


inherit ROOM;

void create()
{
    set("short","����" );
    set("long",  @LONG
����һ�䲼�õ�ʮ�����µĴ��֣�һ����֪���Ǵ�ҹ����ڵ�
�ط����м�Ĳ輸�Ϸ���һ�Ź��٣�һλƯ����С�����ڵ��٣�һ
������������������ˮһ�㣬�������Ķ���ڡ�ǽ�Ϲ���һ�ѽ���
һ���ֻ���������Ȼ���߲��ã�������յ����̨�������յú�������
LONG 
    );
	set("exits", ([
		"out" :__DIR__"ship",
			]));
       set("objects", ([
		"quest/weiguo/japan/japan2.c" : 2,

	]));       
    set("outdoors", "yunhe");
    setup();
	replace_program(ROOM);
	
}


	
