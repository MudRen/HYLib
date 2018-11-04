// gate.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIW "���Ź�" NOR);
	set("long", 
		"�������������������ڡ����Źء���������ǰ������һ���ߴ��\n"
            "��ɫ��¥������������޿�������ж�ǰ������Ϊһ�����Źؾ��޷���\n"
		"�������ˡ�\n");
	set("exits", ([
		"north" : "/d/death/gateway",
	]) );
	set("objects", ([
		__DIR__"npc/wgargoyle":1
	]) );
        set("deathroom",1);
	set("no_fight",1);
        set("no_dazuo", "1");
        set("valid_startroom", "1");
//	set("no_clean_up", 0);
	setup();
}


void init()
{
        object me;
        me = this_player();
        if( !wizardp(me) ) {
        if (me->query_condition("poison_sandu")>1)
        {          me->apply_condition("poison_sandu",0);}
        if (me->query_condition("snake_poison")>1)
        {          me->apply_condition("snake_poison",0);}
        if (me->query_condition("wugong_poison")>1)
        {          me->apply_condition("wugong_poison",0);}
        if (me->query_condition("zhizhu_poison")>1)
        {          me->apply_condition("zhizhu_poison",0);}
        if (me->query_condition("xiezi_poison")>1)
        {          me->apply_condition("xiezi_poison",0);}
        if (me->query_condition("chanchu_poison")>1)
        {          me->apply_condition("chanchu_poison",0);}
        if (me->query_condition("poison_sandu")>1)
        {          me->apply_condition("poison_sandu",0);}

	me->set("startroom",base_name(environment(me)));
        me->save();
	add_action("block_cmd","",1);
	}
}


int block_cmd()
{
	string verb = query_verb();
	if (verb=="who") return 0;
	if (verb=="look") return 0;
	if (verb=="skills") return 0;
	if (verb=="score") return 0;
	if (verb=="quit") return 0;
	if (verb=="hp") return 0;
	return 1;
}
