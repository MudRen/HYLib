// cmds/imm/topdel.c
// idea@yqyl 7.6.2000
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string type,player;
	
	seteuid(geteuid(me));
	
	if (!arg||sscanf(arg,"%s %s",type,player)!=2)
		return notify_fail("ָ���ʽ : topdel <����> <���ID>\n");
		
	if( ob = new("/clone/topten/magic-rice") )
		ob->del_one(player,type);
		else return notify_fail("topten��magic-rice��������\n");

	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : topdel <����> <���ID>

ע��:<����>���� B1,B2,B3...
�ٽ�������,��Ϊֻ�е���������init()��ʱ��,���Ż���°��ϵ�����,
����topdel��,Ҫ�ٴ��ߵ�topboard,����init������,��Ȼ�����Ŀ����Ǿɵ�,û��
HELP
    );
    return 1;
}