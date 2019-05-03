#pragma once
#include<string>
#include<vector>
namespace parsing{
    enum class ND{
	/*算術演算子*/
	UPLUS,    // 単項プラス
	UMINUS,   // 単項マイナス
	PLUS,     // 加算
	MINUS,    // 減算
	MULTI,    // 乗算
	DIVIDE,   // 除算
	REMAIN,   // 剰余
	PREINC,   // 前置インクリメント
	PREDEC,   // 前置デクリメント
	ASSIGN,   // 単純代入
	PLASGN,   // 加算代入
	MIASGN,   // 減算代入
	MUASGN,   // 乗算代入
	DIASGN,   // 除算代入
	RMASGN,   // 剰余代入
	/*比較演算子*/
	EQUAL,    // 等価
	NEQUAL,   // 非等価
	LESS,     // 小なり
	GREAT,    // 大なり
	LEEQ,     // 小なりイコール
	GREQ,     // 大なりイコール
    };
    struct node{
	virtual ~node();
    };
    struct numeric:public node{
	int value;
	numeric(int value);
	~numeric()override;
    };
    struct ident:public node{
	std::string name;
	ident(const std::string&name);
	~ident()override;
    };
    struct unopr:public node{
	ND type;
	node*arg;
	unopr(ND type,node*const arg);
	~unopr()override;
    };
    struct biopr:public node{
	ND type;
	node*larg,*rarg;
	biopr(node*const left,ND type,node*const right);
	~biopr()override;
    };
    struct statement:public node{
	virtual ~statement();
    };
    struct single:public statement{
	node*stat;
	single(node*stat);
	~single()override;
    };
    struct compound:public statement{
	std::vector<statement*>stats;
	compound();
	~compound()override;
	void push_back(statement*const st);
    };
    struct _if_:public statement{
	single*cond;
	statement*st;
	_if_(single*const cond,statement*const st);
	~_if_()override;
    };
    struct _else_:public statement{
	statement*st;
	_else_(statement*const st);
	~_else_()override;
    };
    struct _while_:public statement{
	single*cond;
	statement*st;
	_while_(single*const cond,statement*const st);
	~_while_()override;
    };
}
