 // dagger.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
#include <weapon.h>
#include <ansi.h>
inherit DAGGER; 
void create() {
        set_name(HIW "ȥ�ǵ�" NOR, ({ "dagger" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѵ��泬�������ⲻմѪ�Ķ��С�\n");
                set("value", 400);
                set("material", "steel");
                set("wield_msg", "$N�ӻ�������һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n���뻳�С�\n");
        }
        ::init_dagger(125);
}   
