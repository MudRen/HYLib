inherit ROOM;
string look_sign(object me);
void create()
{
set("short", "˯��");
	set("long", @LONG
�������������ڵ�˯��������С�������Ϲ������ӣ�������Ǽ��ӣ�
û��ʲô��Ķ��������������һ�����ӡ���ǽ�����źܴ�Ļ�.
�
LONG
	);
        set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"yuxuguan",

]));
set("item_desc", ([
		"image": (: look_sign :),
		"��": (: look_sign :),
		
	]) );
       
	set("no_clean_up", 0);

	setup();
//	replace_program(ROOM);
}
string look_sign(object me)
{
	if(me->query_skill("whip",1)<30 ) {
    return " ����һ���Ż�,���������������еĹ��� ��\n";
	} else {
	me->set_temp("yuxu_image",1);
	return "  ����һ���Ż�,���������������еĹ���,������Ů���賤��,
��������, ����ƮƮ,�㶨�˶�����Լ�о������ƺ������ż�Ϊ�����ı޷�\n";
}
}

void init()
{
        add_action("do_huiwu", "huiwu");  
}

int do_huiwu(string arg)
{
	object me=this_player();
	object weapon = me->query_temp("weapon");

    if (!me->query_temp("yuxu_image", 1)) return 0;

    if( !arg || arg!="image" ) {
                write("��Ҫ����ʲô���裡\n");
                return 1;
        }
        if (!weapon || weapon->query("skill_type") != "whip" )
		return notify_fail("�������ޱޣ���ô��᣿\n");

        if ((int)me->query_skill("whip", 1) >100 )
        return notify_fail("���Ѿ��߾�ȫ��ȥ��ử�ϰ��صı޷���Ҫ�������޷���������Ļ����޷��ˣ�\n");
    
	    me->receive_damage("jingli", 10+random(15));
	     me->receive_damage("jing",random(10));
        write("������ŹŻ��ϰ��صı޷����壬�����ţ������������һЩ�йػ����޷��ľ�Ҫ֮���ڡ�\n");
         me->improve_skill("whip", me->query("int"));       
         return 1;
}                                     
int valid_leave(object me, string dir)
{
	me->set_temp("yuxu_image", 0);
       return 1;
	 
}
