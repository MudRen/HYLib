// Room: /d/xiangyang/conglin1.c

inherit ROOM;


void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������ɽ´��Ψһ��һ����·��ɽ����Ȼ������̫�ߣ����Ǽ�
Ϊ���ͣ����ܴ����ܲ�����ʱ����Ұ�޵����С�ֻ�к��о������
���Ÿ������ﲶ�ԣ���˵����Ķ��߹����쳣�׺ݡ�������������
�˼���
LONG	);
	set("exits", ([  
        "eastdown" : __DIR__"outsroad3",
        "westup" : __DIR__"conglin2", 
         "northup" : "/d/jqg/shanlu3", 
]));
	 
        set("outdoors", "xiangyang");
	setup();
}
int valid_leave(object me, string dir)
{
        if ((dir != "westup") && (dir != "eastdown"));
         if ((userp(me)) && (dir == "westup")){
            me->receive_damage("qi", 100);       
            write("���͵�ɽ´�������ĸг�����һ����ͺ���䤱���\n");
    }

        if ((userp(me)) && (dir == "eastdown")){
        me->receive_damage("qi", 100);       
        write("���͵�ɽ´�������ĸг�����һ����ͺ���䤱���\n");
}
        return 1;
}
