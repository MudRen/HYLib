 /* Copyright (C) 1998 Apstone, Inc. */
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "���");
    set("long", @LONG
��ر��������壬Ϊ��ɽ�ڶ��߷壬ɽ�������ѩ����ʹ��ʢ����������ˮ
���¶�Ҳ�൱�͡������εĺ�������󣬵���ˮ��Σ����������ģ����˾ͽ��˸�
�����Ե�ϲ����������ܵ�ɽ���ϣ��������ɼ�֣���ɼ���籦����ͦ�Ρ����룬
�������ơ�����ѩ��ʹ���ͦ�ε������ֵ�ӳ���峺�ĺ�ˮ�У���������ص�����
�ľ�ɫ��
LONG
    );
    set("long_night", @LONG
��ر��������壬Ϊ��ɽ�ڶ��߷壬ɽ�������ѩ����ˮ���Ǻ���̹ǡ�
�����εĺ����������ҹ��΢΢���ӳ���£����ǵ�㣬��Ө���������
�ܵ�ɽ���ϣ�ҹᰳ��𣬳�����ɽ��������������������һ�Դ���ľ�ϡ�
Զ��ѩ��ӳ���ǹ��ں���΢΢����������һ��������õĸо���
LONG
    ); 
    set("exits", ([
        "southdown" : __DIR__"tianshan",
    ]));


        //set("no_pk",1);  
    set("outdoors", "xinjiang");
    set("resource/water",1);
    set("liquid/name","�����ĺ�ˮ");
    set("liquid/container", "���");
        set("coor/x",-1130);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
} 
void init(){

    if (!random(100) ) {
//        remove_call_out("falling_star");
        call_out("falling_star", random(20), this_player());
    }
} 
void falling_star(object me) {
    object *inv, *watchers;
    int i, age; 
    if(!objectp(me)) {
        return;
    }
    if(environment(me) != this_object() ) {
        return;
    }
    if(me->is_fighting()) {
        return;
    }
    message("vision", HIC"\n���Ǵ�Զ���ӹ����֡���������\n"NOR, me);
    message("vision", HIW"           �ں���ĵ�Ӱ������һ�����ò�������Թ�â��\n"NOR, me);
    age = me->query("age");
    if (age >= 26 && age <= 28 && !me->query("����A/��ɽ_����")) {
        tell_object(me,HIG"\n�ڿ������ǵ�һ˲�䣬��ĬĬ�����������˸�Ը��\n"NOR);
        me->add("combat_exp",100);
    me->start_busy(10);
    }
}        
