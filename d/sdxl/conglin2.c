// Room: /d/xiangyang/conglin2.c

inherit ROOM;


void create()
{
	set("short", "ɽ·");
	set("long", @LONG
�����·����Ӷ��ͣ����ϵ��㼣Խ��Խ�١�һ�������ζ
���������洫����ż�����ܿ���һЩ�Ի��ǲ�׽Ұ�޵����塣
LONG	);
	set("exits", ([  
        "eastdown" : __DIR__"conglin1",
        "westup" : __DIR__"conglin3", 
]));
	 
        set("outdoors", "xiangyang");
	setup();
}
int valid_leave(object me, string dir)
{
        if ((dir != "westup") && (dir != "eastdown"));
           if ((userp(me)) && (dir == "westup")){
        me->receive_damage("jing", 40);
            write("���͵�ɽ´�������ĸг�����һ����ͺ���䤱���\n");
    }

        if ((userp(me)) && (dir == "eastdown")){
        me->receive_damage("jing", 100);       
        write("���͵�ɽ´�������ĸг�����һ����ͺ���䤱���\n");
}
        return 1;
}
