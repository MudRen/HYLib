// Room: gudi.c
// bbb 1997/06/11
// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "ɽ�ȵײ�");
	set("long", @LONG
ֻ�����ɽ����һ�����ٲ����������գ��������£�����һ���峺�쳣��
���֮�У����ٲ��������룬��ˮȴ�����磬�ٲ�ע�봦��ˮ���ڣ�ֻ�����
��ʮ���ɣ���ˮ����һƽ�羵������Χ�������Ӳ�(cao)��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"donghubian",            
        ]));
	set("item_desc",([	   
	   "cao" : "һ��Ƭ�Ӳݺ��ҵس��ţ����ȥ��֪��ͨ�����\n"
	]));
	set("no_clean_up", 0);
        set("outdoors", "����");
	setup(); 
}

void init()
{
	add_action("do_zuan", "zuan");
        add_action("do_zuan", "enter");
}

int do_zuan(string arg)
{
	object me;
	me = this_player();
        if (!arg || arg !="cao") 
           return notify_fail("������ʲô����\n");       
	message_vision("$Nһͷ������Ӳݴԡ�\n" , me);
        me->move(__DIR__"xiaoxi");
        write("����ǰһ��������������Ӳݴԡ�\n");
	return 1;
}
