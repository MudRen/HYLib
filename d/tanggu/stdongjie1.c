inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�����������֡����治�����������۶����������������ڳ����ģ�����
��һ��ר���ӻ��ĵ��ӣ����Ͼ��Ǳ���������õ��µꡣ���������Լ������
�ϲ��ٵĴ�ֻ�ľ��ǳ����ĸۿ��ˡ�
LONG );

        set("exits", ([
                "north" : __DIR__"zhahuopu",
		"south" : __DIR__"qianyunge",
		"east" : __DIR__"gangkou",
		"west" : __DIR__"center",
        	
	]));
	set("outdoors", "����");
	setup();
}
