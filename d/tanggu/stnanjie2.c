inherit ROOM;
void create()
{
        set("short", "ʯͷ�Ͻ�");
        set("long", @LONG
�ϴ�����ǳ��еķ����ضΡ����ճ�Ϸ˵�飬���ϵƺ���̵ƺ������Ϊ
���֡�������һ�����ֵĹ㳡��������һ�һ������鱦�У��������������ֽ�
�������������ҫ���������⡣��������һ��������¡��Ǯׯ��
LONG );
        set("exits", ([
                "north" : __DIR__"center",
        	"south" : __DIR__"stnanjie1",
		"west" : __DIR__"qianzhuang",
		"east" : __DIR__"zhubaohang",
	]));

	set("outdoors", "����");

	setup();
}
