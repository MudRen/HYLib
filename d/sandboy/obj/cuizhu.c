#include <ansi.h>

inherit ITEM;

void create()
{
  set_name(HIG+"����"+NOR, ({ "cuizhu" }));
  set_weight(8000);
  set("long","һ����ɫ"+HIG+"����"+NOR+"�Ĵ���.\n");
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("material", "bamboo");
    set("no_get",1);
       set("no_drop",1);
  }
  setup();
}

void init ()
{
  	int i;
	object ob,*inv;
       string str;
       ob=load_object("/d/sandboy/zhushao");
	inv=all_inventory(ob);
	if(!sizeof(inv))	return;
str="һ����ɫ"+HIG+"����"+NOR+"�Ĵ���.����������\n";
str+=
"----------------------------------------------------------------------------------------\n";
	for(i=0;i<sizeof(inv);i++)	{
         str+=RANK_D->query_rank(inv[i])+inv[i]->short()+"\n";
                 }
   set("long",str);
}
